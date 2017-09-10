<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\{Locator, Service, ServiceFactory};

final class LoggerFactory implements ServiceFactory<Logger> {
  public function createService(Locator $locator): Logger {
    return new Logger();
  }
}
