<?hh //strict

namespace HHPack\Service\Example;

use HHPack\Service\Service;
use HHPack\Service\ServiceFactory;
use HHPack\Service\FactoryModule;

final class Production implements FactoryModule
{

    public function getIterator() : Iterator<ServiceFactory>
    {
        yield new LoggerFactory('production');
    }

}
