<?hh //partial

namespace hhpack\servicelocator\spec;

use hhpack\service\ServiceContainer;
use hhpack\service\spec\fixtures\Logger;
use hhpack\service\spec\fixtures\LoggerFactory;
use hhpack\service\spec\fixtures\HttpClient;
use hhpack\service\spec\fixtures\HttpClientFactory;

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
  describe('#count', function() {
    it('returns item count', function () {
      expect($this->container->count())->toBe(2);
    });
  });
  describe('#isEmpty', function() {
    context('when not empty', function() {
      it('returns false', function () {
        expect($this->container->isEmpty())->toBeFalse();
      });
    });
  });
  describe('#items', function() {
    beforeEach(function() {
      $this->items = ImmMap::fromItems($this->container->items());
    });
    it('returns pair item', function () {
      expect($this->items->count())->toBe(2);
    });
  });
});
