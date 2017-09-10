<?hh //strict

namespace HHPack\Service\Example;

use HHPack\Service\Service;
use HHPack\Service\ServiceFactory;
use HHPack\Service\FactoryModule;

final class Development implements FactoryModule
{

    public function getIterator() : Iterator<ServiceFactory>
    {
        yield new LoggerFactory('development');
    }

}
