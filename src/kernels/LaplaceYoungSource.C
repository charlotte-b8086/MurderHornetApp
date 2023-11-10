#include "LaplaceYoungSource.h"

registerMooseObject("MurderHornetApp", LaplaceYoungSource);

InputParameters
LaplaceYoungSource::validParams()
{
  auto params = ADKernelValue::validParams();
  params.addParam<Real>("kappa", 1, "Coefficient to the Laplace Young source term.");
  params.addClassDescription("Source term for Laplace Young equation.");
  return params;
}

LaplaceYoungSource::LaplaceYoungSource(const InputParameters & parameters) : 
    ADKernelValue(parameters), 
    _kappa(getParam<Real>("kappa"))
{}

ADReal
LaplaceYoungSource::precomputeQpResidual()
{
  return _kappa * _u[_qp];
}
