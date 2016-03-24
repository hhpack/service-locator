<?hh //strict

namespace hhpack\service\spec\fixtures;

use hhpack\service\Service;
use hhpack\service\Locator;
use hhpack\service\LocatorContext;
use hhpack\service\FactoryModule;
use hhpack\service\ServiceFactory;

final class TestModule implements FactoryModule
{

    public function getIterator() : Iterator<ServiceFactory<Service>>
    {
        yield new LoggerFactory();
    }

}
