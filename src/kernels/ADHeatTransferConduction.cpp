#include "ADHeatTransferConduction.h"

InputParameters
ADHeatTransferConduction::validParams()
{
  InputParameters params = ADKernelGrad::validParams();

  params.addClassDescription("Compute the heat conduction term in the heat equation.");

  return params;
}

ADHeatTransferConduction::ADHeatTransferConduction(const InputParameters & parameters)
  : ADKernelGrad(parameters),
  _thermalConductivity(50); // W/mK for steel
  {};

ADRealVectorValue
ADHeatTransferConduction::precomputeQpResidual()
{
  return _thermalConductivity * _grad_u[_gp];
}
