<?hh //strict

namespace HHPack\Service\Example;

use HHPack\Service\{Locator};
use HHPack\Service\Service;
use HHPack\Service\ServiceFactory;
use HHPack\Service\Example\LoggerFactory;

final class LoggerFactory implements ServiceFactory
{

    const type T = Logger;

    public function __construct(private string $prefix)
    {
    }

    public function createService(Locator $locator) : Logger
    {
        return new LoggerService($this->prefix);
    }

}
