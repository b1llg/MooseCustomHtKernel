#include "MooseCustomHtKernelApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MooseCustomHtKernelApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

MooseCustomHtKernelApp::MooseCustomHtKernelApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseCustomHtKernelApp::registerAll(_factory, _action_factory, _syntax);
}

MooseCustomHtKernelApp::~MooseCustomHtKernelApp() {}

void 
MooseCustomHtKernelApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<MooseCustomHtKernelApp>(f, af, s);
  Registry::registerObjectsTo(f, {"MooseCustomHtKernelApp"});
  Registry::registerActionsTo(af, {"MooseCustomHtKernelApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MooseCustomHtKernelApp::registerApps()
{
  registerApp(MooseCustomHtKernelApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MooseCustomHtKernelApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseCustomHtKernelApp::registerAll(f, af, s);
}
extern "C" void
MooseCustomHtKernelApp__registerApps()
{
  MooseCustomHtKernelApp::registerApps();
}
