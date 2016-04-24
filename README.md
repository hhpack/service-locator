# service-locator

[![Latest Stable Version](https://poser.pugx.org/hhpack/service-locator/v/stable)](https://packagist.org/packages/hhpack/service-locator)
[![Build Status](https://travis-ci.org/hhpack/service-locator.svg?branch=master)](https://travis-ci.org/hhpack/service-locator)
[![Dependency Status](https://www.versioneye.com/user/projects/56efa78e35630e00388897c3/badge.svg?style=flat)](https://www.versioneye.com/user/projects/56efa78e35630e00388897c3)
[![License](https://poser.pugx.org/hhpack/service-locator/license)](https://packagist.org/packages/hhpack/service-locator)

## Basic usage

Implementing a factory of creating service.

```hack
use hhpack\service\Locator;
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
    public function createService(Locator<Service> $locator) : Logger
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

## Module for environment

By using the **EnvironmentModule**, you will be able to load a module based on the setting of **HHVM_ENV**.

When HHVM_ENV is the **production** looks for a module named **Production** from the specified directory.

```hack
use hhpack\service\ServiceLocator;
use hhpack\service\EnvironmentModule;

$module = new EnvironmentModule([
    Pair { 'hhpack\\service\\example\\', __DIR__ } // autoload for module
]);

$locator = ServiceLocator::fromModule($module);

$logger = $locator->lookup(Logger::class);
$logger->put('logger loaded');
```

By executing the **environment.hh** of example, it can be confirmed.


* development

		$ HHVM_ENV=development hhvm example/environment.hh
		$ development - logger loaded

* production

		$ HHVM_ENV=production hhvm example/environment.hh
		$ production - logger loaded


## Run the test

You can run the test with the following command.

	composer install
	composer test
	
