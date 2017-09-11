<?hh //strict

namespace HHPack\ServiceLocator\Test\Fixtures;

use HHPack\ServiceLocator\{Locator, Service, ServiceFactory};

final class LoggerFactory implements ServiceFactory {
  const type T = Logger;

  public function createService(Locator $locator): this::T {
    return new Logger();
  }
}
