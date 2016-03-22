<?hh //strict

namespace hhpack\service\spec\fixtures;

use hhpack\service\ServiceFactory;

final class HttpClientFactory implements ServiceFactory<HttpClient>
{
    public function createService() : HttpClient
    {
        return new HttpClient();
    }
}
