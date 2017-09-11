<?hh //strict

namespace HHPack\Service\Test;

use HHPack\Service\Registry\{ServiceRegistry};
use HHPack\Service\Test\Fixtures\{
  Logger,
  LoggerFactory,
  HttpClient,
  HttpClientFactory
};
use HackPack\HackUnit\Contract\Assert;

final class ServiceRegistryTest {

  public function __construct(private ServiceRegistry $container) {}

  <<SuiteProvider('Factories')>>
  public static function createByItems(): this {
    $container =
      new ServiceRegistry([new LoggerFactory(), new HttpClientFactory()]);
    return new static($container);
  }

  <<Test('Factories')>>
  public function container(Assert $assert): void {
    $assert->int($this->container->count())->eq(2);
    $assert->bool($this->container->isEmpty())->is(false);

    $items = ImmMap::fromItems($this->container->items());
    $assert->int($this->container->count())->eq(2);
  }

  <<Test('Factories')>>
  public function lookupByClassNameString(Assert $assert): void {
    $assert->mixed($this->container->lookup((string) Logger::class))
      ->isTypeOf(LoggerFactory::class);
    $assert->mixed($this->container->lookup((string) HttpClient::class))
      ->isTypeOf(HttpClientFactory::class);
  }
}
