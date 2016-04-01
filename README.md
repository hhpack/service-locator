# service-locator

[![Latest Stable Version](https://poser.pugx.org/hhpack/service-locator/v/stable)](https://packagist.org/packages/hhpack/service-locator)
[![Build Status](https://travis-ci.org/hhpack/service-locator.svg?branch=master)](https://travis-ci.org/hhpack/service-locator)
[![Dependency Status](https://www.versioneye.com/user/projects/56efa78e35630e00388897c3/badge.svg?style=flat)](https://www.versioneye.com/user/projects/56efa78e35630e00388897c3)
[![License](https://poser.pugx.org/hhpack/service-locator/license)](https://packagist.org/packages/hhpack/service-locator)

## Basic usage

Implementing a factory of creating service.

```hack
use hhpack\service\Service;
use hhpack\service\ServiceFactory;

interface Logger implements Service
{
}

final class LoggerService implements Logger
{
}

final class LoggerFactory implements ServiceFactory<Logger>
{
    public function createService() : Logger
    {
        return new LoggerService();
    }
}
```

Specify the **ServiceFactory**, to create a service locator.

```hack
use hhpack\service\ServiceLocator;

$locator = ServiceLocator::fromItems([
    new LoggerFactory()
]);
$logger = $locator->lookup(Logger::class);
```

## Module of service factory

By using the modules that provide **ServiceFactory**, you can generate a new service locator.

```hack
use hhpack\service\Service;
use hhpack\service\ServiceFactory;
use hhpack\service\FactoryModule;

final class CustomModule implements FactoryModule
{

    public function getIterator() : Iterator<ServiceFactory<Service>>
    {
        yield new LoggerFactory();
    }

}
```

Using the defined modules, and generates a new service locator.

```hack
use hhpack\service\ServiceLocator;

$locator = ServiceLocator::fromModule(new CustomModule());

$logger = $locator->lookup(Logger::class);
$logger->put('logger loaded');
```

## Run the test

You can run the test with the following command.

	composer install
	composer test
	
