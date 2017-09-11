<?hh //strict

namespace HHPack\ServiceLocator\Test\Fixtures;

use HHPack\ServiceLocator\{Locator, Service, ServiceFactory};

final class HttpClientFactory implements ServiceFactory {
  const type T = HttpClient;

  public function createService(Locator $locator): this::T {
    return new HttpClient();
  }
}
