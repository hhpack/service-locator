<?hh //strict

namespace hhpack\service\example;

use hhpack\service\Locator;
use hhpack\service\Service;
use hhpack\service\ServiceFactory;
use hhpack\service\example\LoggerFactory;

final class LoggerFactory implements ServiceFactory<Logger>
{

    public function __construct(private string $prefix)
    {
    }

    public function createService(Locator<Service> $locator) : Logger
    {
        return new LoggerService($this->prefix);
    }

}
