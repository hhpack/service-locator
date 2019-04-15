namespace HHPack\ServiceLocator\Example;

use HHPack\ServiceLocator\{Service, ServiceFactory, Module};

final class Production implements Module {

  public function getIterator(): Iterator<ServiceFactory> {
    yield new LoggerFactory('production');
  }

}
