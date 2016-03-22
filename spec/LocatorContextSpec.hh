<?hh //partial

namespace hhpack\servicelocator\spec;

use hhpack\servicelocator\LocatorContext;
use hhpack\servicelocator\spec\fixtures\Logger;
use hhpack\servicelocator\spec\fixtures\LoggerFactory;
use hhpack\servicelocator\spec\fixtures\HttpClient;
use hhpack\servicelocator\spec\fixtures\HttpClientFactory;

describe(LocatorContext::class, function() {
  beforeEach(function() {
    $this->context = new LocatorContext([
      new LoggerFactory(),
      new HttpClientFactory()
    ]);
  });
  describe('#lookup', function() {
    it('returns service instance', function () {
      expect($this->context->lookup(Logger::class))->toBeAnInstanceOf(Logger::class);
      expect($this->context->lookup(HttpClient::class))->toBeAnInstanceOf(HttpClient::class);
    });
  });
});
