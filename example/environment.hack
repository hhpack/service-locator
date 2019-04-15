namespace HHPack\ServiceLocator\Example;

require_once __DIR__.'/../vendor/hh_autoload.hh';

use HHPack\ServiceLocator\{ServiceLocator};
use HHPack\ServiceLocator\Module\{EnvironmentModule};

<<__EntryPoint>>
function main(): noreturn {
  $module = new EnvironmentModule(
    [Pair {'HHPack\\Service\\Example\\', __DIR__}],
  );

  $locator = ServiceLocator::fromModule($module);

  $logger = $locator->lookup(Logger::class);
  $logger->put('logger loaded');

  exit(0);
}
