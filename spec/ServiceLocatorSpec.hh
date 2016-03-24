<?hh //partial

namespace hhpack\service\spec;

use hhpack\service\ServiceLocator;
use hhpack\service\LocatorContext;
use hhpack\service\spec\fixtures\TestModule;
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
    it('returns service', function () {
      expect($this->locator->lookup(Logger::class))->toBeAnInstanceOf(Logger::class);
      expect($this->locator->lookup(HttpClient::class))->toBeAnInstanceOf(HttpClient::class);
    });
  });
  describe('#fromModule', function() {
    it('returns locator context instance', function () {
      $locator = ServiceLocator::fromModule(TestModule::class);
      expect($locator->lookup(Logger::class))->toBeAnInstanceOf(Logger::class);
    });
  });
});
