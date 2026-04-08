using UnrealBuildTool;
using System.Collections.Generic;

public class UEStalkerEditorTarget : TargetRules
{
    public UEStalkerEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        // Обновлено для UE 5.7
        DefaultBuildSettings = BuildSettingsVersion.V6;

        // Версия порядка включений
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;

        // Основной игровой модуль
        ExtraModuleNames.Add("UEStalker");
    }

    // Rider автоматически создаёт этот метод, можно оставить пустым
    private void RegisterModulesCreatedByRider()
    {
        ExtraModuleNames.AddRange(new string[] { });
    }
}