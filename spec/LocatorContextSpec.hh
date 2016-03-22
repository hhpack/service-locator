<?hh //partial

namespace hhpack\service\spec;

use hhpack\service\LocatorContext;
use hhpack\service\spec\fixtures\Logger;
use hhpack\service\spec\fixtures\LoggerFactory;
use hhpack\service\spec\fixtures\HttpClient;
use hhpack\service\spec\fixtures\HttpClientFactory;

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
