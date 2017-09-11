<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\{Locator, Service, ServiceFactory};

final class LoggerFactory implements ServiceFactory {
  const type T = Logger;

  public function createService(Locator $locator): this::T {
    return new Logger();
  }
}
