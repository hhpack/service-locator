<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\{Locator, Service, ServiceFactory};

final class HttpClientFactory implements ServiceFactory<HttpClient> {
  public function createService(Locator $locator): HttpClient {
    return new HttpClient();
  }
}
