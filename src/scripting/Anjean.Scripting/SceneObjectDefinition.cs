namespace Anjean;

public sealed record SceneObjectDefinition(
    Type ObjectType,
    Dictionary<IPropKey, object?> Props
);

public static class SceneObject
{
    public static SceneObjectDefinition DefineObject<TGameObject>(
        Dictionary<IPropKey, object?> props
    )
        where TGameObject : GameObject
    {
        return new SceneObjectDefinition(typeof(TGameObject), props);
    }
}