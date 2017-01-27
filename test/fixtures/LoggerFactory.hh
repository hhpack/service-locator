<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\Locator;
use HHPack\Service\Service;
use HHPack\Service\ServiceFactory;

final class LoggerFactory implements ServiceFactory<Logger>
{
    public function createService(Locator<Service> $locator) : Logger
    {
        return new Logger();
    }
}
