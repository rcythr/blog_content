#include <clang/AST/ASTConsumer.h>
#include <clang/Frontend/FrontendPluginRegistry.h>

struct MyASTConsumer : public clang::ASTConsumer {
  void HandleTranslationUnit(clang::ASTContext& ctx) override {
    ctx.getTranslationUnitDecl()->dump();
  }
};

struct MyPluginAction : public clang::PluginASTAction {
  virtual ~MyPluginAction() {}

  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
      clang::CompilerInstance& CI, llvm::StringRef InFile) override {
    return std::make_unique<MyASTConsumer>();
  }

  bool ParseArgs(const clang::CompilerInstance& CI,
                 const std::vector<std::string>& arg) override {
    return true;
  }

  ActionType getActionType() override { return AddAfterMainAction; }
};

static clang::FrontendPluginRegistry::Add<MyPluginAction> X(
    "MyPlugin",
    "Does interesting things with an AST.");
