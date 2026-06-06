namespace Anjean;

internal sealed class InternalCamera : InternalGameObject
{
    internal InternalCamera(uint id) : base(id) {}

    internal void SetFieldOfView(float fieldOfView)
    {
        int rc = Native.Anjean_Camera_SetFieldOfView(Id, fieldOfView);

        if (rc != 0)
        {
            throw new InvalidOperationException(
                $"Failed to set camera field of view. rc={rc}"
            );
        }
    }

    internal void SetNearClippingPlane(float nearClippingPlane)
    {
        int rc = Native.Anjean_Camera_SetNearClippingPlane(Id, nearClippingPlane);

        if (rc != 0)
        {
            throw new InvalidOperationException(
                $"Failed to set camera near clipping plane. rc={rc}"
            );
        }
    }

    internal void SetFarClippingPlane(float farClippingPlane)
    {
        int rc = Native.Anjean_Camera_SetFarClippingPlane(Id, farClippingPlane);

        if (rc != 0)
        {
            throw new InvalidOperationException(
                $"Failed to set camera far clipping plane. rc={rc}"
            );
        }
    }

    internal void SetAspectRatio(float aspectRatio)
    {
        int rc = Native.Anjean_Camera_SetAspectRatio(Id, aspectRatio);

        if (rc != 0)
        {
            throw new InvalidOperationException(
                $"Failed to set camera aspect ratio. rc={rc}"
            );
        }
    }
    

    internal void SetAsCurrentCamera()
    {
        int rc = Native.Anjean_Runtime_SetCurrentCamera(Id);

        if (rc != 0)
        {
            throw new InvalidOperationException(
                $"Failed to set current camera. rc={rc}"
            );
        }
    }
}