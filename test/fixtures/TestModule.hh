<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\Service;
use HHPack\Service\Locator;
use HHPack\Service\LocatorContext;
use HHPack\Service\FactoryModule;
use HHPack\Service\ServiceFactory;

final class TestModule implements FactoryModule
{

    public function getIterator() : Iterator<ServiceFactory<Service>>
    {
        yield new LoggerFactory();
    }

}
