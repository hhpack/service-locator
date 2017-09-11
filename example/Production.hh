<?hh //strict

namespace HHPack\Service\Example;

use HHPack\Service\{Service, ServiceFactory, Module};

final class Production implements Module {

  public function getIterator(): Iterator<ServiceFactory> {
    yield new LoggerFactory('production');
  }

}
