<?hh //strict

namespace hhpack\servicelocator\spec\fixtures;

use hhpack\servicelocator\ServiceFactory;

final class HttpClientFactory implements ServiceFactory<HttpClient>
{
    public function createService() : HttpClient
    {
        return new HttpClient();
    }
}
