<?hh //strict

namespace HHPack\Service\Test;

use HHPack\Service\LocatorContext;
use HHPack\Service\Test\Fixtures\{ Logger, LoggerFactory, HttpClient, HttpClientFactory };
use HackPack\HackUnit\Contract\Assert;

final class LocatorContextTest
{
    <<Test>>
    public function lookupByClassName(Assert $assert): void
    {
        $context = new LocatorContext([
            new LoggerFactory(),
            new HttpClientFactory()
        ]);
        $assert->mixed($context->lookup(Logger::class))->isTypeOf(Logger::class);
        $assert->mixed($context->lookup(HttpClient::class))->isTypeOf(HttpClient::class);
    }
}
