<?hh //strict

namespace hhpack\service\spec\fixtures;

use hhpack\service\Locator;
use hhpack\service\Service;
use hhpack\service\ServiceFactory;

final class LoggerFactory implements ServiceFactory<Logger>
{
    public function createService(Locator<Service> $locator) : Logger
    {
        return new Logger();
    }
}
