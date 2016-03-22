# service-locator

[![Latest Stable Version](https://poser.pugx.org/hhpack/service-locator/v/stable)](https://packagist.org/packages/hhpack/service-locator)
[![Build Status](https://travis-ci.org/hhpack/service-locator.svg?branch=master)](https://travis-ci.org/hhpack/service-locator)
[![Dependency Status](https://www.versioneye.com/user/projects/56efa78e35630e00388897c3/badge.svg?style=flat)](https://www.versioneye.com/user/projects/56efa78e35630e00388897c3)
[![License](https://poser.pugx.org/hhpack/service-locator/license)](https://packagist.org/packages/hhpack/service-locator)

## Basic usage

Implementing a factory of creating service.

```hack
use hhpack\servicelocator\Service;
use hhpack\servicelocator\ServiceFactory;

final class Logger implements Service
{
}

final class LoggerFactory implements ServiceFactory<Logger>
{
    public function createService() : Logger
    {
        return new Logger();
    }
}
```

Specify the **ServiceFactory**, to create a service locator.

```hack
$locator = ServiceLocator::fromItems([
    new LoggerFactory()
]);
$logger = $locator->lookup(Logger::class);
```

