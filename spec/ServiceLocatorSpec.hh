<?hh //partial

namespace hhpack\servicelocator\spec;

use hhpack\servicelocator\ServiceLocator;
use hhpack\servicelocator\spec\fixtures\Logger;
use hhpack\servicelocator\spec\fixtures\LoggerFactory;
use hhpack\servicelocator\spec\fixtures\HttpClient;
use hhpack\servicelocator\spec\fixtures\HttpClientFactory;

describe(ServiceLocator::class, function() {
  beforeEach(function() {
    $this->locator = ServiceLocator::fromItems([
      new LoggerFactory(),
      new HttpClientFactory()
    ]);
  });
  describe('#lookup', function() {
    it('returns service factory', function () {
      expect($this->locator->lookup(Logger::class))->toBeAnInstanceOf(Logger::class);
      expect($this->locator->lookup(HttpClient::class))->toBeAnInstanceOf(HttpClient::class);
    });
  });
});
