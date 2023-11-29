/*
 *  PGMcpp : PRIMED Grid Modelling (in C++)
 *
 *  Anthony Truelove MASc, P.Eng.
 *  email:  gears1763@tutanota.com
 *  github: gears1763-2
 *
 *  See license terms
 *
 */


///
/// \file PYBIND11_Production.cpp
///
/// \brief Bindings file for the Production class. Intended to be #include'd in
///     PYBIND11_PGM.cpp
///
/// Ref: \cite pybind11\n
///
/// A file which instructs pybind11 how to build Python bindings for the Production
/// class. Only public attributes/methods are bound!
///


pybind11::class_<ProductionInputs>(m, "ProductionInputs")
    .def_readwrite("print_flag", &ProductionInputs::print_flag)
    .def_readwrite("is_sunk", &ProductionInputs::is_sunk)
    .def_readwrite("capacity_kW", &ProductionInputs::capacity_kW)
    .def_readwrite("nominal_inflation_annual", &ProductionInputs::nominal_inflation_annual)
    .def_readwrite("nominal_discount_annual", &ProductionInputs::nominal_discount_annual)
    .def_readwrite("replace_running_hrs", &ProductionInputs::replace_running_hrs)
    
    .def(pybind11::init());


pybind11::class_<Production>(m, "Production")
    .def_readwrite("interpolator", &Production::interpolator)
    .def_readwrite("print_flag", &Production::print_flag)
    .def_readwrite("is_running", &Production::is_running)
    .def_readwrite("is_sunk", &Production::is_sunk)
    .def_readwrite("n_points", &Production::n_points)
    .def_readwrite("n_starts", &Production::n_starts)
    .def_readwrite("n_replacements", &Production::n_replacements)
    .def_readwrite("n_years", &Production::n_years)
    .def_readwrite("running_hours", &Production::running_hours)
    .def_readwrite("replace_running_hrs", &Production::replace_running_hrs)
    .def_readwrite("capacity_kW", &Production::capacity_kW)
    .def_readwrite("nominal_inflation_annual", &Production::nominal_inflation_annual)
    .def_readwrite("nominal_discount_annual", &Production::nominal_discount_annual)
    .def_readwrite("real_discount_annual", &Production::real_discount_annual)
    .def_readwrite("capital_cost", &Production::capital_cost)
    .def_readwrite(
        "operation_maintenance_cost_kWh",
        &Production::operation_maintenance_cost_kWh
    )
    .def_readwrite("net_present_cost", &Production::net_present_cost)
    .def_readwrite("total_dispatch_kWh", &Production::total_dispatch_kWh)
    .def_readwrite(
        "levellized_cost_of_energy_kWh",
        &Production::levellized_cost_of_energy_kWh
    )
    .def_readwrite("type_str", &Production::type_str)
    .def_readwrite("is_running_vec", &Production::is_running_vec)
    .def_readwrite("production_vec_kW", &Production::production_vec_kW)
    .def_readwrite("dispatch_vec_kW", &Production::dispatch_vec_kW)
    .def_readwrite("storage_vec_kW", &Production::storage_vec_kW)
    .def_readwrite("curtailment_vec_kW", &Production::curtailment_vec_kW)
    .def_readwrite("capital_cost_vec", &Production::capital_cost_vec)
    .def_readwrite(
        "operation_maintenance_cost_vec",
        &Production::operation_maintenance_cost_vec
    )
      
    .def(pybind11::init<>())
    .def(pybind11::init<int, double, ProductionInputs>())
    .def("handleReplacement", &Production::handleReplacement)
    .def("computeRealDiscountAnnual", &Production::computeRealDiscountAnnual)
    .def("computeEconomics", &Production::computeEconomics)
    .def("commit", &Production::commit);
