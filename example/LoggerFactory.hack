namespace HHPack\ServiceLocator\Example;

use HHPack\ServiceLocator\{Locator};
use HHPack\ServiceLocator\Service;
use HHPack\ServiceLocator\ServiceFactory;
use HHPack\ServiceLocator\Example\LoggerFactory;

final class LoggerFactory implements ServiceFactory {

  const type T = Logger;

  public function __construct(private string $prefix) {}

  public function createService(Locator $locator): this::T {
    return new LoggerService($this->prefix);
  }

}
