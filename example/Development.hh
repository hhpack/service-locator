<?hh //strict

namespace hhpack\service\example;

use hhpack\service\Service;
use hhpack\service\ServiceFactory;
use hhpack\service\FactoryModule;

final class Development implements FactoryModule
{

    public function getIterator() : Iterator<ServiceFactory<Service>>
    {
        yield new LoggerFactory('development');
    }

}
