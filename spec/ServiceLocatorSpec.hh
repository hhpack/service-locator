<?hh //partial

namespace hhpack\servicelocator\spec;

use hhpack\service\ServiceLocator;
use hhpack\service\spec\fixtures\Logger;
use hhpack\service\spec\fixtures\LoggerFactory;
use hhpack\service\spec\fixtures\HttpClient;
use hhpack\service\spec\fixtures\HttpClientFactory;

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
