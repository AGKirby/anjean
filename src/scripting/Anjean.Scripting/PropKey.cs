namespace Anjean;

public interface IPropKey
{
    string Name { get; }
    Type ValueType { get; }
}

public sealed class PropKey<T> : IPropKey
{
    public string Name { get; }

    public Type ValueType => typeof(T);

    public PropKey(string name)
    {
        Name = name;
    }

    public override string ToString() => Name;
}