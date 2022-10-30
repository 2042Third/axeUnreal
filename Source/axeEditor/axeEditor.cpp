#include "axeEditor.h"

#include "MoveComponentVisualizer.h"
#include "axe/MoveComponent.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FaxeEditorModule, axeEditor);

void FaxeEditorModule::StartupModule()
{
	// Check if editor is valid
	if (GUnrealEd)
	{
		TSharedPtr<FMoveComponentVisualizer> MoveVisualizer = MakeShareable(new FMoveComponentVisualizer);
		if (MoveVisualizer.IsValid())
		{
			GUnrealEd -> RegisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName(), MoveVisualizer);
			MoveVisualizer -> OnRegister();
		}
	}
}

void FaxeEditorModule::ShutdownModule()
{
	if (GUnrealEd)
	{
		GUnrealEd -> UnregisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName());
	}
}
