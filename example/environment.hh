<?hh //partial

namespace HHPack\Service\Example;

require_once __DIR__.'/../vendor/autoload.php';

use HHPack\Service\{ ServiceLocator };
use HHPack\Service\Module\{ EnvironmentModule };

function main(): void {
  $module =
    new EnvironmentModule([Pair {'HHPack\\Service\\Example\\', __DIR__}]);

  $locator = ServiceLocator::fromModule($module);

  $logger = $locator->lookup(Logger::class);
  $logger->put('logger loaded');
}

main();
