#include "DialogueEditor/DialogueEditor.h"
#include "DialogueEditor/IDialogueModuleInterface.h"
#include "Framework/Docking/TabManager.h"
#include "Widgets/Docking/SDockTab.h"

class FDialogueEditorWindowBase : public IDialogueModuleListenerInterface, public TSharedFromThis< FDialogueEditorWindowBase >
{
public:

	virtual ~FDialogueEditorWindowBase(){}
	// IPixelopusToolBase
	virtual void OnStartupModule() override
	{
		Initialize();
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabName, FOnSpawnTab::CreateRaw(this, &FDialogueEditorWindowBase::SpawnTab))
			.SetGroup(FDialogueEditor::Get().GetMenuRoot())
			.SetDisplayName(TabDisplayName)
			.SetTooltipText(ToolTipText);
	};

	virtual void OnShutdownModule() override
	{
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TabName);
	};

	// In this function set TabName/TabDisplayName/ToolTipText
	virtual void Initialize() {};
	virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs) { return SNew(SDockTab); };

	virtual void MakeMenuEntry(FMenuBuilder& menuBuilder)
	{
		FGlobalTabmanager::Get()->PopulateTabSpawnerMenu(menuBuilder, TabName);
	};

protected:
	FName TabName;
	FText TabDisplayName;
	FText ToolTipText;
};