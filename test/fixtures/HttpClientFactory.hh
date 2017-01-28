<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\Locator;
use HHPack\Service\Service;
use HHPack\Service\ServiceFactory;

final class HttpClientFactory implements ServiceFactory<HttpClient>
{
    public function createService(Locator<Service> $locator) : HttpClient
    {
        return new HttpClient();
    }
}
