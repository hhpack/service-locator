<?hh //strict

namespace hhpack\service;

use IteratorAggregate;

interface FactoryModule extends IteratorAggregate<ServiceFactory<Service>>, Traversable<ServiceFactory<Service>>
{
    public function getIterator() : Iterator<ServiceFactory<Service>>;
}
