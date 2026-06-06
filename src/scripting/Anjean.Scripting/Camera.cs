namespace Anjean;

public class Camera : GameObject
{
    private static Camera? currentCamera;
    public new class Props : GameObject.Props
    {
        protected Props() {}

        public static readonly PropKey<float> FieldOfView =
            new("Camera.FieldOfView");

        public static readonly PropKey<float> NearClippingPlane =
            new("Camera.NearClippingPlane");

        public static readonly PropKey<float> FarClippingPlane =
            new("Camera.FarClippingPlane");

        public static readonly PropKey<float> AspectRatio =
            new("Camera.AspectRatio");

        public static readonly PropKey<bool> IsCurrent =
            new("Camera.IsCurrent");
    }

    public float FieldOfView { get; private set; } = 60f;
    public float NearClippingPlane { get; private set; } = 0.1f;
    public float FarClippingPlane { get; private set; } = 1000f;
    public float AspectRatio { get; private set; } = 16f / 9f;

    private InternalCamera InternalCamera =>
        (InternalCamera)InternalGameObject;

    internal override InternalGameObject CreateInternalObject()
    {
        int rc = Native.Anjean_Runtime_CreateCamera(out uint id);

        if (rc != 0)
        {
            throw new InvalidOperationException(
                $"Failed to create native camera. rc={rc}"
            );
        }

        return new InternalCamera(id);
    }

    protected override void ApplyProps()
    {
        FieldOfView = GetProp(Props.FieldOfView, 60f);
        NearClippingPlane = GetProp(Props.NearClippingPlane, 0.1f);
        FarClippingPlane = GetProp(Props.FarClippingPlane, 1000f);
        AspectRatio = GetProp(Props.AspectRatio, 16f / 9f);

        InternalCamera.SetFieldOfView(FieldOfView);
        InternalCamera.SetNearClippingPlane(NearClippingPlane);
        InternalCamera.SetFarClippingPlane(FarClippingPlane);
        InternalCamera.SetAspectRatio(AspectRatio);

        bool isCurrent = GetProp(Props.IsCurrent, false);

        if (isCurrent)
        {
            InternalCamera.SetAsCurrentCamera();

            currentCamera = this;
        }
    }

  public static Camera GetCurrentCamera()
    {
        if (currentCamera is null)
        {
            throw new InvalidOperationException("No current camera has been set.");
        }

        return currentCamera;
    }
}