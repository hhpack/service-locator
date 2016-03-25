<?hh //partial

namespace hhpack\service\example;

require_once __DIR__ . '/../vendor/autoload.php';

use hhpack\service\ServiceLocator;
use hhpack\service\EnvironmentModule;

function main() : void
{
    $module = new EnvironmentModule([
        Pair { 'hhpack\\service\\example\\', __DIR__ }
    ]);

    $locator = ServiceLocator::fromModule($module);

    $logger = $locator->lookup(Logger::class);
    $logger->put('logger loaded');
}

main();
