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
/// \file Tidal.h
///
/// \brief Header file the Tidal class.
///


#ifndef TIDAL_H
#define TIDAL_H


#include "Renewable.h"


///
/// \enum TidalProductionModel
///
/// \brief An enumeration of the various tidal power production models supported by
///     PGMcpp.
///

enum TidalPowerProductionModel {
    CUBIC, ///< A cubic power production model
    EXPONENTIAL, ///< An exponential power production model
    N_TIDALPOWERPRODUCTIONMODELS ///< A simple hack to get the number of elements in RenewableType
};


///
/// \struct TidalInputs
///
/// \brief A structure which bundles the necessary inputs for the Tidal constructor.
///     Provides default values for every necessary input. Note that this structure
///     encapsulates RenewableInputs.
///

struct TidalInputs {
    RenewableInputs renewable_inputs; ///< An encapsulated RenewableInputs instance.
    
    int resource_key = 0; ///< A key used to index into the Resources object, to associate this asset with the appropriate resource time series.
    
    double capital_cost = -1; ///< The capital cost of the asset (undefined currency). -1 is a sentinel value, which triggers a generic cost model on construction (in fact, any negative value here will trigger). Note that the generic cost model is in terms of Canadian dollars [CAD].
    double operation_maintenance_cost_kWh = -1; ///< The operation and maintenance cost of the asset [1/kWh] (undefined currency). This is a cost incurred per unit of energy produced. -1 is a sentinel value, which triggers a generic cost model on construction (in fact, any negative value here will trigger). Note that the generic cost model is in terms of Canadian dollars [CAD/kWh].
    
    double design_speed_ms = 3; ///< The tidal stream speed [m/s] at which the tidal turbine achieves its rated capacity.
    
    TidalPowerProductionModel power_model = TidalPowerProductionModel :: CUBIC; ///< The tidal power production model to be applied.
};


///
/// \class Tidal
///
/// \brief A derived class of the Renewable branch of Production which models tidal
///     production.
///

class Tidal : public Renewable {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __checkInputs(TidalInputs);
        
        double __getGenericCapitalCost(void);
        double __getGenericOpMaintCost(void);
        
        double __computeCubicProductionkW(int, double, double);
        double __computeExponentialProductionkW(int, double, double);
        
        
    public:
        //  1. attributes
        double design_speed_ms; ///< The tidal stream speed [m/s] at which the tidal turbine achieves its rated capacity.
        
        TidalPowerProductionModel power_model; ///< The tidal power production model to be applied.
        
        //  2. methods
        Tidal(void);
        Tidal(int, TidalInputs);
        
        double computeProductionkW(int, double, double);
        double commit(int, double, double, double);
        
        ~Tidal(void);
        
};  /* Tidal */


#endif  /* TIDAL_H */
