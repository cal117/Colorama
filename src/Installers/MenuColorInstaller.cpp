#include "Installers/MenuColorInstaller.hpp"

#include "lapiz/shared/utilities/ZenjectExtensions.hpp"

#include "UI/ColoramaFlowCoordinator.hpp"
#include "UI/MenuButtonManager.hpp"

#include "Coloring/Services/ColorizerService.hpp"
#include "UI/ConfigViewController.hpp"
#include "Coloring/Services/DefaultMenuService.hpp"

#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/DiContainer.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"

DEFINE_TYPE(Colorama::Installers, MenuColorInstaller)

using namespace Colorama::Coloring::Services;
using namespace Colorama::UI;

void Colorama::Installers::MenuColorInstaller::InstallBindings() {
  auto container = get_Container();

  Lapiz::Zenject::ZenjectExtensions::FromNewComponentOnNewGameObject(container->Bind<ColoramaFlowCoordinator*>())->AsSingle()->NonLazy();
  Lapiz::Zenject::ZenjectExtensions::FromNewComponentAsViewController(container->Bind<ConfigViewController*>())->AsSingle()->NonLazy();

  container->BindInterfacesAndSelfTo<MenuButtonManager*>()->AsSingle();

//  container->Bind<ColorizerService*>()->To<DefaultMenuService*>()->AsSingle();
}