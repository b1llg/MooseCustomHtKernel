//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MooseCustomHtKernelTestApp.h"
#include "MooseCustomHtKernelApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
MooseCustomHtKernelTestApp::validParams()
{
  InputParameters params = MooseCustomHtKernelApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

MooseCustomHtKernelTestApp::MooseCustomHtKernelTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseCustomHtKernelTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MooseCustomHtKernelTestApp::~MooseCustomHtKernelTestApp() {}

void
MooseCustomHtKernelTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MooseCustomHtKernelApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MooseCustomHtKernelTestApp"});
    Registry::registerActionsTo(af, {"MooseCustomHtKernelTestApp"});
  }
}

void
MooseCustomHtKernelTestApp::registerApps()
{
  registerApp(MooseCustomHtKernelApp);
  registerApp(MooseCustomHtKernelTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MooseCustomHtKernelTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseCustomHtKernelTestApp::registerAll(f, af, s);
}
extern "C" void
MooseCustomHtKernelTestApp__registerApps()
{
  MooseCustomHtKernelTestApp::registerApps();
}
