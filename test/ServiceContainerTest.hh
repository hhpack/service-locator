<?hh //strict

namespace HHPack\Service\Test;

use HHPack\Service\ServiceContainer;
use HHPack\Service\Test\Fixtures\{ Logger, LoggerFactory, HttpClient, HttpClientFactory };
use HackPack\HackUnit\Contract\Assert;

final class ServiceContainerTest
{
    <<Test>>
    public function container(Assert $assert): void
    {
        $container = new ServiceContainer([
            new LoggerFactory(),
            new HttpClientFactory()
        ]);
        $assert->int($container->count())->eq(2);
        $assert->bool($container->isEmpty())->is(false);

        $items = ImmMap::fromItems($container->items());
        $assert->int($container->count())->eq(2);
    }

    <<Test>>
    public function lookupByClassNameString(Assert $assert): void
    {
        $container = new ServiceContainer([
            new LoggerFactory(),
            new HttpClientFactory()
        ]);
        $assert->mixed($container->lookup((string) Logger::class))->isTypeOf(LoggerFactory::class);
        $assert->mixed($container->lookup((string) HttpClient::class))->isTypeOf(HttpClientFactory::class);
    }
}
