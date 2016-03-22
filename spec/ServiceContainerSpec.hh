<?hh //partial

namespace hhpack\servicelocator\spec;

use hhpack\servicelocator\ServiceContainer;
use hhpack\servicelocator\spec\fixtures\Logger;
use hhpack\servicelocator\spec\fixtures\LoggerFactory;
use hhpack\servicelocator\spec\fixtures\HttpClient;
use hhpack\servicelocator\spec\fixtures\HttpClientFactory;

describe(ServiceContainer::class, function() {
  beforeEach(function() {
    $this->container = new ServiceContainer([
      new LoggerFactory(),
      new HttpClientFactory()
    ]);
  });
  describe('#lookup', function() {
    it('returns service factory', function () {
      expect($this->container->lookup((string) Logger::class))->toBeAnInstanceOf(LoggerFactory::class);
      expect($this->container->lookup((string) HttpClient::class))->toBeAnInstanceOf(HttpClientFactory::class);
    });
  });
});
