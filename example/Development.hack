namespace HHPack\ServiceLocator\Example;

use HHPack\ServiceLocator\{Service, ServiceFactory, Module};

final class Development implements Module {

  public function getIterator(): Iterator<ServiceFactory> {
    yield new LoggerFactory('development');
  }

}
