<?hh //strict

namespace hhpack\service\spec\fixtures;

use hhpack\service\Locator;
use hhpack\service\Service;
use hhpack\service\ServiceFactory;

final class HttpClientFactory implements ServiceFactory<HttpClient>
{
    public function createService(Locator<Service> $locator) : HttpClient
    {
        return new HttpClient();
    }
}
