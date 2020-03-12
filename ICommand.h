#pragma once
class I_Command {
public:
    virtual void Execute() = 0;
    virtual I_Command* clone() = 0;
    virtual ~I_Command() = default;
};