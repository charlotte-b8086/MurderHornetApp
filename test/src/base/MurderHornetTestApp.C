//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MurderHornetTestApp.h"
#include "MurderHornetApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
MurderHornetTestApp::validParams()
{
  InputParameters params = MurderHornetApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

MurderHornetTestApp::MurderHornetTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MurderHornetTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MurderHornetTestApp::~MurderHornetTestApp() {}

void
MurderHornetTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MurderHornetApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MurderHornetTestApp"});
    Registry::registerActionsTo(af, {"MurderHornetTestApp"});
  }
}

void
MurderHornetTestApp::registerApps()
{
  registerApp(MurderHornetApp);
  registerApp(MurderHornetTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MurderHornetTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MurderHornetTestApp::registerAll(f, af, s);
}
extern "C" void
MurderHornetTestApp__registerApps()
{
  MurderHornetTestApp::registerApps();
}
